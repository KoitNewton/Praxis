using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace WQ
{
    /// <summary>
    /// 文本文件。
    /// </summary>
    public class txtFile
    {
        /// <summary>
        /// 打印日志。
        /// </summary>
        /// <param name="ID">标识。</param>
        /// <param name="content">内容。</param>
        public void Log(string ID, string content)
        {
            string date = DateTime.Now.ToLongDateString();                              // 日期格式：2022年11月24日
            string time = DateTime.Now.TimeOfDay.ToString();                            // 时间格式：00:30:41.4349226
 
            string logDirectory = Directory.GetCurrentDirectory() + @"\Log";            // log文件夹。
            string logPath = logDirectory + $@"\{date}.txt";                            // log路径。
 
            if (Directory.Exists(logDirectory) == false)                                // 判断log文件夹是否存在。
                Directory.CreateDirectory(logDirectory);
 
            string str = $"{date} {time}   {ID}   {content}{"\r\n"}";
            File.AppendAllText(logPath, str);                                           // 将log写入并换行。
            Console.Write(str);                                                         // 控制台打印log。
        }
 
    }
}