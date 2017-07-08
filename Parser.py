import xml.etree.ElementTree as ET
import re
import subprocess

class Advertisement:
    district = ""
    street = ""
    house_number = ""
    rooms_count = 0
    price = 0
    square = 0
    pass

def post_parse():
    # Здесь должен быть вызов файла tomitaparser.exe с передачей ему config.proto
    subprocess.run([r'tomitaparser.exe',r'config.proto'])
    result = xml_parse()
    return result

def xml_parse():
    result = Advertisement()

    tree = ET.parse('output.xml').getroot()[0][0]
    if tree.find('Address') is not None:
        result.street = tree.find('./Address/Street').attrib.get('val')
        result.house_number = tree.find('./Address/House').attrib.get('val')
    if tree.find('Square') is not None:
        result.square = int(re.match(r'\d+',tree.find('./Square/Square').attrib.get('val')).group(0))
    if tree.find('District') is not None:
        result.district = tree.find('./District/District').attrib.get('val')
    if tree.find('Price') is not None:
        result.price = price_parse(tree.find('./Price/Price').attrib.get('val'))
    if tree.find('Rooms') is not None:
        result.rooms_count = rooms_parse(tree.find('./Rooms/Rooms').attrib.get('val'))
    return result

#Возвращает численное значение цены
def price_parse(val):
    #print (val)
    if re.search(r'Т|т|К|к',val) is not None: #Если в строке есть "т", "тыс" или "к"
        split_list = re.split(r'Т|т|К|к',val) #Получаем число, указанное до этого
        price = int(split_list[0])*1000 #Умножаем его на 1000
    elif re.search(r'млн|МЛН',val) is not None: #Иначе если в строке есть "млн"
        split_list = re.split(r'млн|МЛН',val) #Получаем число, указанное до этого
        price = int(split_list[0])*1000000 #Умножаем его на 1000000
    else: #Иначе получаем число, идущее в строке до любого из указанных дескрипторов валюты
        split_list = re.split(r'р|Р|руб|РУБ|Руб|рублей|Рублей|РУБЛЕЙ', val)
        price = int(split_list[0])
    return price #Возвращаем полученное число

#Возвращает численное значение количества комнат
def rooms_parse(val):
    #print (val)
    match_res = re.match(r'\d+',val) #Проверяем, есть ли в начале строки цифра
    if match_res is not None: #Если есть, принимаем ее за количество комнат
        rooms_count = int(match_res.group(0))
    elif re.match(r'ОДН',val) is not None: #Иначе проверяем строку на все возможные буквенные обозначения количества комнат
        rooms_count = 1 #Получаем соответствующее число
    elif re.match(r'ДВУ',val) is not None:
        rooms_count = 2
    elif re.match(r'ТРЕ|ТРЁ', val) is not None:
        rooms_count = 3
    elif re.match(r'ЧЕТЫР', val) is not None:
        rooms_count = 4
    elif re.match(r'ПЯТ', val) is not None:
        rooms_count = 5
    return rooms_count #Возвращаем полученное число


print(post_parse().square)