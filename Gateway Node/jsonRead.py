import json,urllib
from collections import namedtuple
import serial
from time import sleep

ser = serial.Serial("/dev/ttyAMA0")
ser.baudrate = 9600
url = "http://sh.digitalenginedevelopers.com/getData.php"

while True:
	data = urllib.urlopen(url).read()
	output = json.loads(data)
	#print(output)
	if output['Thresholds'][0]['node'] == 'node1':
		a=output['Thresholds'][0]['hvac']
		
		if(int(a)<10):
                        s='$DATA:**1*T*000'+str(a)+'*'
		elif(int(a)<100):
			s='$DATA:**1*T*00'+str(a)+'*'
		elif(int(a)<1000):
			s='$DATA:**1*T*0'+str(a)+'*'
		else:
			s='$DATA:**1*T*'+str(a)+'*'
		print s
        	ser.write(s)
		sleep(2)


		#if output['Thresholds'][1]['node'] == 'node2':
		#        a=output['Thresholds'][1]['hvac']
		#	s='*2*T*'+str(a)+'*';
		#	print a
		#        ser.write(s)
		#	sleep(2)
		#if output['Thresholds'][2]['node'] == 'node3':
		#	a=output['Thresholds'][2]['hvac']
		#	s='*3*T*'+str(a)+'*';
		#	print a
		#        ser.write(s)
		#	sleep(2)

	#data = urllib.urlopen(url).read()
	#output = json.loads(data)
	if output['Thresholds'][0]['node'] == 'node1':
        	b=output['Thresholds'][0]['light']  
		
		if(int(b)<10):
                        s='$DATA:**1*L*000'+str(b)+'*'
                elif(int(b)<100):
                        s='$DATA:**1*L*00'+str(b)+'*'
                elif(int(b)<1000):
                        s='$DATA:**1*L*0'+str(b)+'*'
                else:
                        s='$DATA:**1*L*'+str(b)+'*'
        	print s
        	ser.write(s)
        	sleep(2)

ser.close();
#print(out['Thresholds']['node'])
#print(output[1]['hvac'])
#result = []
#for item in output:
#    my_dict={}
#    my_dict['node1']=item.get('node1').get('hvac')
#    my_dict['mode2']=item.get('node2').get('hvac')
#    my_dict['node3']=item.get('node3').get('hvac')
#    print my_dict
#    result.append(my_dict)
