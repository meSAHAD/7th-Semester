import os
import requests
from bs4 import BeautifulSoup
import time

current_url = "http://books.toscrape.com/catalogue/page-1.html"
base_url = "http://books.toscrape.com/catalogue/"

# Output file to save scraped contents (explicit path to this script's folder)
output_path = os.path.join(os.path.dirname(__file__), "scraped_books.txt")

with open(output_path, "w", encoding="utf-8") as out_file:
    while current_url:
        print(f"Scraping: {current_url}")
        out_file.write(f"Scraping: {current_url}\n")
        
        response = requests.get(current_url)
        if response.status_code != 200:
            break
            
        soup = BeautifulSoup(response.text, 'html.parser')
        books = soup.find_all('article', class_='product_pod')

        for book in books:
            title = book.h3.a['title']
            price = book.find('p', class_='price_color').text
            print(f" - {title}: {price}")
            out_file.write(f" - {title}: {price}\n")

        out_file.write("\n")

        # --- THE CRAWLING LOGIC ---
        # Look for the 'next' button
        next_button = soup.find('li', class_='next')
        
        if next_button:
            # Get the relative link (e.g., 'page-2.html')
            next_page_rel = next_button.find('a')['href']
            # Combine it with the base URL to get the full link
            current_url = base_url + next_page_rel
            
            time.sleep(1) 
        else:
            print("\nReached the last page. Happy days!")
            out_file.write("Reached the last page. Happy days!\n")
            current_url = None

print(f"Saved results to {output_path}")