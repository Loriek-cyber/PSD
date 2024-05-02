from selenium import webdriver
from selenium.webdriver.chrome.options import Options

# Opzioni per il browser headless
chrome_options = Options()
chrome_options.add_argument('--headless')  # Avvia il browser in modalità headless

# Path al driver di Chrome (assicurati di averlo installato e configurato correttamente)
chrome_driver_path = 'path_al_tuo_driver_di_chrome'

# Inizializza il driver di Chrome
driver = webdriver.Chrome(executable_path=chrome_driver_path, options=chrome_options)

# URL della pagina web da cui prendere l'elemento
url = 'https://example.com'

# Carica la pagina web
driver.get(url)

# Trova l'elemento desiderato (ad esempio, il titolo della pagina)
element = driver.find_element_by_xpath('//*[@id="qmQuoteTable"]/div[2]/div/div/div/div[1]/div/div[2]/div/div/div[1]/div[1]/span[1]')

# Stampa il testo dell'elemento
print("Testo dell'elemento:", element.text)

# Chiudi il browser
driver.quit()
