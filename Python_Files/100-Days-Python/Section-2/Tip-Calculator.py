print("Welcome to the tip calculator!\n")
total_bill = int(input("What was the total bill? "))
tip_percentage = int(input("How much tip would you like to give? 10, 12, or 15? "))
num_people = int(input("How many people should split the bill? "))
amount_pp = (total_bill + ((tip_percentage / 100) * total_bill)) / num_people
print("Each person should pay: " + str(amount_pp))