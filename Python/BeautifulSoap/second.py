from bs4 import BeautifulSoup
import requests
url=raw_input("Enter website Url==")
r=requests.get("http://"+url);
data=r.text
soup=BeautifulSoup(data)
tag1=soup.find_all('div')
for i in tag1:
	try:
		print(i.attrs)
	except:
		print("none")
