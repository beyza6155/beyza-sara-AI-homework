import csv

# 1. Initialize a dictionary to store language counts
counts = {}

# 2. Read the original favorites.csv
with open("favorites.csv", "r") as input_file:
    reader = csv.DictReader(input_file)
    for row in reader:
        lang = row["language"]
        # Increment count for each language found
        counts[lang] = counts.get(lang, 0) + 1

# 3. Write results to language_summary.csv
with open("language_summary.csv", "w", newline="") as output_file:
    # Define the column headers
    fieldnames = ["language", "votes"]
    
    # Create the writer object
    writer = csv.DictWriter(output_file, fieldnames=fieldnames)
    
    # Write the header row
    writer.writeheader()
    
    # Write the data rows
    # Sorting by language name makes the CSV easier for humans to read
    for lang in sorted(counts):
        writer.writerow({"language": lang, "votes": counts[lang]})

print("Summary complete! Created language_summary.csv")
