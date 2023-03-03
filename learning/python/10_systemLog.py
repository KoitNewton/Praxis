import os
import codecs
from lxml import etree
import Evtx.Evtx as evtx

def evtxFile(absolutePath, filenameWithExt, ext, _fromDate, _toDate):
    print("Reading: " + filenameWithExt)

    outText = ""
    channel = ""

    #read the windows event viewer log and convert its contents to XML
    with codecs.open(tempFilePath, "a+", "utf-8", "ignore") as tempFile:
        with evtx.Evtx(absolutePath) as log:
            for record in log.records():
                xmlLine = record.xml()
                xmlLine = xmlLine.replace(" xmlns=\"http://schemas.microsoft.com/win/2004/08/events/event\"", "")
                xmlParse = etree.XML(xmlLine)
                level = parseXMLtoString(xmlParse, ".//Level/text()")

                if not level == "0" and not level == "4":
                    providerName = parseXMLtoString(xmlParse, ".//Provider/@Name")
                    qualifiers = parseXMLtoString(xmlParse, ".//EventID/@Qualifiers")
                    timestamp = parseXMLtoString(xmlParse, ".//TimeCreated/@SystemTime")
                    eventID = parseXMLtoString(xmlParse, ".//EventID/text()")
                    task = parseXMLtoString(xmlParse, ".//Task/text()")
                    keywords = parseXMLtoString(xmlParse, ".//Keywords/text()")
                    eventRecordID = parseXMLtoString(xmlParse, ".//EventRecordID/text()")
                    channel = parseXMLtoString(xmlParse, ".//Channel/text()")
                    computer = parseXMLtoString(xmlParse, ".//Computer/text()")
                    message = parseXMLtoString(xmlParse, ".//Data/text()")

                    if level == "1":
                        level = "Critical"
                    elif level == "2":
                        level = "Error"
                    elif level == "3":
                        level = "Warning"
                                
                    date = timestamp[0:10]
                    time = timestamp[11:19]
                    time = time.replace(".", "")

                    _date = datetime.strptime(date, "%Y-%m-%d").date()
                                        
                    if _fromDate <= _date <= _toDate:

                        message = message.replace("<string>", "")
                        message = message.replace("</string>", "")
                        message = message.replace("\r\n", " ")
                        message = message.replace("\n\r", " ")
                        message = message.replace("\n", " ")
                        message = message.replace("\r", " ")
                                    
                        outText = date + " " + time + "|" + level + "|" + message.strip() + "|" + task + "|" + computer + "|" + providerName + "|" + qualifiers + "|" + eventID + "|" + eventRecordID + "|" + keywords + "\n"

                        tempFile.writelines(outText)

    with codecs.open(tempFilePath, "r", "utf-8", "ignore") as tempFile2:
        myLinesFromDateRange = tempFile2.readlines()
            
    #delete the temporary file that was created
    os.remove(tempFilePath)          

    if len(myLinesFromDateRange) > 0:
        createFolder("\\filtered_data_files\\")
        outFilename = "windows_" + channel.lower() + "_event_viewer_logs" + ext

        myLinesFromDateRange.sort()
        #remove duplicate records from the list
        myFinalLinesFromDateRange = list(set(myLinesFromDateRange))
        myFinalLinesFromDateRange.sort()

        with codecs.open(os.getcwd() + "\\filtered_data_files\\" + outFilename, "a+", "utf-8", "ignore") as linesFromDateRange:
            linesFromDateRange.seek(0)
            if len(linesFromDateRange.read(100)) > 0:
                linesFromDateRange.writelines("\n")
            linesFromDateRange.writelines(myFinalLinesFromDateRange)
        del myLinesFromDateRange[:]
        del myFinalLinesFromDateRange[:]
    else:
        print("No data was found within the specified date range.")

    print("Closing: " + filenameWithExt)