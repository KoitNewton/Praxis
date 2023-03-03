# make sure you adjust this to point to the folder you want to monitor

$year = (Get-Date).Year
$month = (get-date).Month
$day = (get-date).Day
#$date = Get-Date
$hour = (get-date).Hour
$minute = (get-date).Minute
$PathToMonitor = "C:\Windows\Prefetch"
$filepath = "./log-$year-$month-$day.log"
 

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

    $FullPath = $details.FullPath

    $OldFullPath = $details.OldFullPath

    $OldName = $details.OldName

    $ChangeType = $details.ChangeType

    $Timestamp = $event.TimeGenerated

    $text = "{0} was {1} at {2}" -f $Name, $ChangeType, $Timestamp

    #Write-Host ""

    Write-Output $text  >> "$filepath"  

   

    # you can also execute code based on change type here

    switch ($ChangeType)

    {
        'Changed' { "CHANGE" }

        'Created' { "CREATED"}

        'Deleted' { "DELETED"

            # uncomment the below to mimick a time intensive handler

            <#

            Write-Host "Deletion Handler Start" -ForegroundColor Gray

            Start-Sleep -Seconds 4   

            Write-Host "Deletion Handler End" -ForegroundColor Gray

            #>

        }

        'Renamed' {
            # this executes only when a file was renamed

            $text = "File {0} was renamed to {1}" -f $OldName, $Name

            Write-Output $text  >> "$filepath"  

        }

        default {Write-Output $text  >> "$filepath"   }

    }

}

 

# add event handlers

$handlers = . {
    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Changed -Action $Action -SourceIdentifier FSChange

    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Created -Action $Action -SourceIdentifier FSCreate

    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Deleted -Action $Action -SourceIdentifier FSDelete

    Register-ObjectEvent -InputObject $FileSystemWatcher -EventName Renamed -Action $Action -SourceIdentifier FSRename

}

 
Write-Output "监视开始时间于$year-$month-$day-$hour-$minute"  >> "$filepath"  


 
try

{
    do

    {
        Wait-Event -Timeout 1
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

    "命令结束"
    

}
