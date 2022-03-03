import serial
import MySQLdb

dbcon = MySQLdb.connect("localhost","root","AyayaMeg0521!","arduino") or die ("could not connect to database")

try:
    print("Connecting....")
    arduino = serial.Serial(port='COM2', baudrate=9600)
except:
    print("Failed to connect")
    
x=0

while 1:
    try:
        arduinodata = arduino.readline()
        sensordata = arduinodata.decode("utf-8")
        print(sensordata)

        s1 = sensordata.find("wsp") + len("wsp")
        e1 = sensordata.find(",ap")
        windspeed = sensordata[s1:e1]

        s2 = sensordata.find(",ap") + len(",ap")
        e2 = sensordata.find(",wl")
        airpressure = sensordata[s2:e2]

        s3 = sensordata.find(",wl") + len(",wl")
        e3 = sensordata.find(",hu")
        waterlevel = sensordata[s3:e3]

        s4 = sensordata.find(",hu") + len(",hu")
        e4 = sensordata.find(",tc")
        humidity = sensordata[s4:e4]

        s5 = sensordata.find(",tc") + len(",tc")
        e5 = sensordata.find(",tf")
        celcius = sensordata[s5:e5]

        s6 = sensordata.find(",tf") + len(",tf")
        e6 = sensordata.find("yas")
        fff = sensordata[s6:e6]

        

        

        try:
            #now = datetime.now()
            
            cursor = dbcon.cursor()
            cursor.execute("insert into weatherdata values ("+ windspeed + "," + airpressure + "," + waterlevel + "," + humidity + "," + celcius + "," + fff + "," + "now()" + ")") #insert
            dbcon.commit()
            cursor.close()
        except MySQLdb.IntegrityError:
            print("Failed to insert")
        finally:
            cursor.close()
    except:
        print("Failed to get data")

