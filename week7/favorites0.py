import csv

# Open favorites.csv for reading
with open("favorites.csv", "r") as file:

    # Create a csv.reader object
    reader = csv.reader(file)

    # Skip the header row (Timestamp, language, problem)
    # next() moves the internal file pointer to the second line
    next(reader)

    # Loop over the remaining rows and print the language column (index 1)
    for row in reader:
        print(row[1])
