
menu = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}
total = 0
print("h", "i",sep="**")
while True:
    try:
        item = input("Item: ")
    except EOFError:
        print("\n")
        break
    if item.title() in menu:
        total += menu[item.title()]
        print("Total: $%.2f" %total)
