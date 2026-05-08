import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = {}  # Keys will be languages, values will be integers

    for row in reader:
        favorite = row["language"]
        
        # If the language is already in our dictionary, add 1 to its value
        if favorite in counts:
            counts[favorite] += 1
        # If it's the first time we've seen this language, "initialize" it to 1
        else:
            counts[favorite] = 1

    # Print each key-value pair
    for language in counts:
        print(f"{language}: {counts[language]}")
