###THE CODE IS WRONG !!!!!!!!

# # This script is made for getting the information of  the Application.evtx by using powershell
#Get-Date -Format "dddd yyyy-MM-dd HH:mm K"
$year = (Get-Date).Year
$month = (get-date).Month
$day = (get-date).Day
$date = Get-Date
$hour = (get-date).Hour
$minute = (get-date).Minute
#New-Item -Path "C:\" -Name "Log_$year+$month+$day.log" 
# # Get-EventLog -List >> "开关机日志_$year-$month-$day.log"
Remove-Item ./*.log -Force
# # Write-Output "First Part is Security" >> "开关机日志_$year-$month-$day.log" 
# # Get-EventLog  -LogName Security -After $year/$month/$day  >> "开关机日志_$year-$month-$day.log" 
# # Write-Output "Second Part is System" >> "开关机日志_$year-$month-$day.log" 
# # Get-EventLog  -LogName System -After $year/$month/$day  >> "开关机日志_$year-$month-$day.log" 
# # Write-Output "Third Part is Application" >> "开关机日志_$year-$month-$day.log" 
# # Get-EventLog  -LogName Application -After $year/$month/$day  >> "开关机日志_$year-$month-$day.log" 
Get-EventLog -LogName system -Source user32 -After $year/$month/$day | Select-Object TimeGenerated, Message `
    | Sort-Object message | Format-Table -Wrap >> "Log_$year+$month+$day.log" 
# # #Get-EventLog -LogName System -Source user32 -After $year/$month/$day  

# make sure you adjust this to point to the folder you want to monitor

$PathToMonitor = "C:\Windows\Prefetch\"

 

explorer $PathToMonitor

 

$FileSystemWatcher = New-Object System.IO.FileSystemWatcher

$FileSystemWatcher.Path  = $PathToMonitor

$FileSystemWatcher.IncludeSubdirectories = $true

 

# make sure the watcher emits events

$FileSystemWatcher.EnableRaisingEvents = $true

 

# define the code that should execute when a file change is detected

$Action = {

    $details = $event.SourceEventArgs

    $Name = $details.Name

    #$FullPath = $details.FullPath

    #$OldFullPath = $details.OldFullPath

    $OldName = $details.OldName

    $ChangeType = $details.ChangeType

    $Timestamp = $event.TimeGenerated

    $text = "{0} was {1} at {2}" -f $Name, $ChangeType, $Timestamp

    #Write-Output ""

    Write-Output $text >> "C:\Log_$year+$month+$day.log" 

   

    # you can also execute code based on change type here

    switch ($ChangeType)

    {

        'Changed' { "CHANGE" }

        'Created' { "CREATED"}

        'Deleted' { "DELETED"

            # uncomment the below to mimick a time intensive handler

            <#

            Write-Output "Deletion Handler Start" -ForegroundColor Gray

            Start-Sleep -Seconds 4   

            Write-Output "Deletion Handler End" -ForegroundColor Gray

            #>

        }


        default { Write-Output $_ >> "C:\Log_$year+$month+$day.log" 
    }

}

 

# add event handlers

$handlers = . {

    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Changed -Action $Action -SourceIdentifier FSChange

    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Created -Action $Action -SourceIdentifier FSCreate

    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Deleted -Action $Action -SourceIdentifier FSDelete

    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Renamed -Action $Action -SourceIdentifier FSRename

}

 

Write-Output "开始监视的时间是$date" >> "C:\Log_$year+$month+$day.log" 

try {
    do
    {
        Wait-Event -Timeout 10
        Write-Host "小时是$hour"
        $hour = (get-date).Hour
    } while ($hour -lt 23)
}



finally

{

    # this gets executed when user presses CTRL+C

    # remove the event handlers

    Unregister-Event -SourceIdentifier FSChange

    Unregister-Event -SourceIdentifier FSCreate

    Unregister-Event -SourceIdentifier FSDelete

    Unregister-Event -SourceIdentifier FSRename

    # remove background jobs

    $handlers | Remove-Job

    # remove filesystemwatcher

    $FileSystemWatcher.EnableRaisingEvents = $false

    $FileSystemWatcher.Dispose()

    "今天的监视结束了~"

}

}


#########这是一个失败版本
