#! python
from mechanize import Browser, _http
from BeautifulSoup import BeautifulSoup

br = Browser()    
br.set_handle_robots(False)
br.addheaders = [('User-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1')]

url = "http://www.stackoverflow.com"
page = br.open(url)
# html = page.read()

# soup = BeautifulSoup(html)
# print soup.prettify()

br.select_form(name="jobref")
br["value"]  = "PO64"

# submit the request
response1 = br.submit()

# print the response, by calling the read() method
print response1.read()
