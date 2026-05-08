import csv

# Dictionary to store {Language: {Problem: Count}}
counts = {}

# Open and read the CSV
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    
    for row in reader:
        lang = row["language"]
        prob = row["problem"]
        
        # If the language isn't in our dictionary yet, add it
        if lang not in counts:
            counts[lang] = {}
        
        # If the problem isn't in the language's sub-dictionary, initialize it
        if prob not in counts[lang]:
            counts[lang][prob] = 0
            
        counts[lang][prob] += 1

# Print the Table
print(f"{'Language':<15} | {'Most Common Problem':<25} | {'Count'}")
print("-" * 55)

for lang in sorted(counts):
    # Find the problem with the maximum count for this language
    # 'key=counts[lang].get' tells max() to compare values, not names
    most_common = max(counts[lang], key=counts[lang].get)
    num_votes = counts[lang][most_common]
    
    print(f"{lang:<15} | {most_common:<25} | {num_votes}")
