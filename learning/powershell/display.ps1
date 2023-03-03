$date = Get-Date
New-Item -Path c:\log_today.log
Write-Output "日志日期为：$date" >> "c:\log_today.log"
Get-ChildItem C:\Windows\Prefetch -recurse  | Out-File -FilePath C:\log_today.log -Append