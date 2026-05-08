import csv

# ── Step 1: Read the CSV and count languages ──────────────────────────────────
counts = {}

with open("../../week1/favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # Get the language from the row
        language = row["language"]

        # Update counts — increment if exists, create if new
        # Using .get() is a clean way to handle keys that don't exist yet
        counts[language] = counts.get(language, 0) + 1

# ── Step 2: Sort by popularity (most popular first) ───────────────────────────
# sorted() returns a list of keys. The 'key' argument tells Python
# to look at the values (the counts) when deciding the order.
sorted_languages = sorted(counts, key=counts.get, reverse=True)

# ── Step 3: Print the report ──────────────────────────────────────────────────
print("=== Language Popularity Report ===")

# Loop over sorted_languages with enumerate() to get rank numbers
# enumerate(list, start=1) gives us (1, "Python"), (2, "C"), etc.
for rank, language in enumerate(sorted_languages, start=1):
    votes = counts[language]
    # :<10 pads the language name to ensure the colons stay aligned
    print(f"{rank}. {language:<10} : {votes} students")

# Print the total number of responses
total = sum(counts.values())
print(f"\nTotal responses: {total}")
