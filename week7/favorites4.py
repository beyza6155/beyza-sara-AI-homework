import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    # Create three counter variables starting at 0
    scratch = 0
    c = 0
    python = 0

    for row in reader:
        favorite = row["language"]
        
        # Use if/elif to increment the correct counter
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

    # Print the counts using f-strings
    print(f"Scratch: {scratch}")
    print(f"C: {c}")
    print(f"Python: {python}")
