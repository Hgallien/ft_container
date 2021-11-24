
import requests
from bs4 import BeautifulSoup
import colorama as color

RED = color.Fore.RED
RESET = color.Fore.RESET
GREEN = color.Fore.GREEN
BLUE = color.Fore.BLUE

def print_red(txt):
  print(RED, txt, RESET)
def print_green(txt):
  print(GREEN, txt, RESET)
def print_blue(txt):
  print(BLUE, txt, RESET)

r = requests.get("https://www.cplusplus.com/reference/vector/vector/")
print_red("STATUS CODE")
print(r.status_code)
print()
print_red("TEXT")
print(r.text)
print()
soup = BeautifulSoup(r.text, "html.parser")
tags = soup.find_all("dl", "links")

for tag in tags:
  route = tag.find("a")["href"]
  url = "https://www.cplusplus.com" + route
  # print_red("using URL " + url)
  print_red('// ' + route.split('/')[-2].strip())
  r = requests.get(url)
  soup = BeautifulSoup(r.text, "html.parser")
  if (soup.find("span", "C_ico cpp11warning")):
    # print_blue("C++11 exclusive")
    continue
  protos = soup.find("div", "C_prototype")
  protos98 = protos.find("div", title="C++98")
  if (protos98):
    # print_green("C++98 found")
    protos = protos98
  # else:
  #   print_blue("C++98 not found")
  texts = [x.text.replace('\r', '').strip() for x in protos.find_all("pre")]
  print('\n'.join(texts))
  # print(protos.find_all("pre"))


