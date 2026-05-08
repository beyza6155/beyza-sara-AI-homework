import csv

with open("favorites.csv", "r") as file:
    # DictReader uses the first line of the CSV to label every column
    reader = csv.DictReader(file)
    
    # We don't need next(reader) because DictReader already "consumed" 
    # the header to create the keys for our dictionaries.
    for row in reader:
        # Access the data by the header name instead of a number
        print(row["language"])
