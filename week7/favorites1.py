import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    
    for row in reader:
        # By assigning row[1] to 'favorite', we make the logic 
        # below it immediately obvious to any other developer.
        favorite = row[1]
        
        print(favorite)
