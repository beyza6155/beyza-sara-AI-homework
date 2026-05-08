import csv

# 1. Ask for user input
try:
    min_votes = int(input("Minimum vote count: "))
except ValueError:
    print("Please enter a valid number.")
    exit(1)

# 2. Open the file
# Using 'with' ensures the file closes automatically, even if an error occurs
with open("favorites.csv", "r") as file:
    
    # 3. Create a DictReader
    # This treats each row as a dictionary where the keys are the header names
    reader = csv.DictReader(file)
    
    print(f"\nResults with at least {min_votes} votes:")
    print("-" * 30)

    # 4. Iterate and filter
    found = False
    for row in reader:
        # Assuming your CSV has columns named 'title' and 'votes'
        # We must convert the vote count from string to int for comparison
        votes = int(row["votes"])
        
        if votes >= min_votes:
            print(f"{row['title']}: {votes} votes")
            found = True

    if not found:
        print("No matches found.")
