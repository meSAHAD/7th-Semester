import requests
from bs4 import BeautifulSoup

local_url = "http://127.0.0.1:5500/SEO/Assignment%201/dummy%20website%20for%20Learning%20ML/index.html"

try:
    response = requests.get(local_url)
    
    # Check if the server is actually running
    if response.status_code == 200:
        print("Successfully connected to local server!\n")
        
        # 2. Parse the HTML
        soup = BeautifulSoup(response.text, 'html.parser')
        
        # 3. Practice extracting your specific content
        page_title = soup.find('h1')
        if page_title:
            print(f"Main Header found: {page_title.text.strip()}")
            
        print("\n--- Links found on your page ---")
        for link in soup.find_all('a'):
            print(f"Link Text: {link.text.strip()} | Destination: {link.get('href')}")
            
    else:
        print(f"Could not find page. Status code: {response.status_code}")
        print("Make sure 'Live Server' is running in VS Code.")

except requests.exceptions.ConnectionError:
    print("Error: Connection Refused.")
    print("Is your Live Server running at http://127.0.0.1:5500?")