from bs4 import BeautifulSoup
import requests
url =raw_input("Enter a website")
r=requests.get("http://"+url)
data=r.text
soup=BeautifulSoup(data)
print(soup.title)
