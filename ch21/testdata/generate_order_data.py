import math
import random
import sys


class Customer:

    def __init__(self, name, address, phone_number):
        self.name = name
        self.address = address
        self.phone_number = phone_number


class Product:

    def __init__(self, name, unit_price):
        self.name = name
        self.unit_price = unit_price


CUSTOMERS = [
    Customer('Alice', 'Washington', '1000'),
    Customer('Bob', 'Texas', '1001'),
    Customer('Cindy', 'New York', '1002'),
    Customer('Dale', 'Mississippi', '1003'),
    Customer('Eric', 'North Carolina', '1004'),
    Customer('Frank', 'California', '1004'),
    Customer('Grace', 'Alabama', '1006'),
    Customer('Helen', 'Hawaii', '1007'),
    Customer('Issac', 'Florida', '1008'),
    Customer('Jack', 'Missouri', '1009'),
    Customer('Kevin', 'Pennsylvania', '1010'),
    Customer('Leo', 'Ohio', '1011'),
    Customer('Michael', 'Vermont', '1012'),
    Customer('Nancy', 'South Carolina', '1013'),
    Customer('Olivia', 'Arizona', '1014'),
    Customer('Peter', 'New Mexico', '1015'),
]

PRODUCTS = [
    Product('apple', 6.23),
    Product('banana', 7.3),
    Product('orange', 9.98),
    Product('grape', 10.77),
    Product('strawberry', 39.5),
    Product('pineapple', 5.16),
    Product('watermelon', 3.78),
    Product('lemon', 7.25),
    Product('cherry', 9.98),
    Product('kiwi', 5.98),
    Product('peach', 9.86),
    Product('bread', 5.8),
    Product('cake', 12.9),
    Product('biscuit', 15.9),
    Product('chocolate', 45.9),
    Product('candy', 16.5),
]

if __name__ == '__main__':
    with open(sys.argv[1], 'w') as f:
        for c in random.sample(CUSTOMERS, 12):
            f.write(f'{{ "{c.name}" "{c.address}" "{c.phone_number}" ')
            n_product = random.randint(1, 10)
            for p in random.sample(PRODUCTS, n_product):
                count = math.ceil(random.expovariate(0.5))
                f.write(f'("{p.name}" {p.unit_price} {count}) ')
            f.write('}\n')
