import sqlite3

# Connect to the database
# This creates a 'connection' object
db = sqlite3.connect("favorites.db")

# A 'cursor' allows us to execute SQL commands and fetch results
cursor = db.cursor()

def main():
    while True:
        print("\n--- SQL Explorer ---")
        print("1. Show all unique languages")
        print("2. Count votes for a specific language")
        print("3. Show the most common problem overall")
        print("4. Exit")
        
        choice = input("Select an option: ")

        if choice == "1":
            # SELECT DISTINCT finds unique values
            cursor.execute("SELECT DISTINCT(language) FROM favorites ORDER BY language")
            rows = cursor.fetchall()
            for row in rows:
                print(row[0]) # row is a tuple, e.g., ("Python",)

        elif choice == "2":
            lang = input("Which language? ")
            # Use '?' as a placeholder to prevent SQL Injection attacks
            cursor.execute("SELECT COUNT(*) FROM favorites WHERE language = ?", (lang,))
            count = cursor.fetchone()[0]
            print(f"{lang} has {count} votes.")

        elif choice == "3":
            # Combining COUNT, GROUP BY, and ORDER BY
            cursor.execute("""
                SELECT problem, COUNT(*) AS n 
                FROM favorites 
                GROUP BY problem 
                ORDER BY n DESC 
                LIMIT 1
            """)
            result = cursor.fetchone()
            if result:
                print(f"Most common problem: {result[0]} ({result[1]} votes)")

        elif choice == "4":
            print("Goodbye!")
            break
        
        else:
            print("Invalid choice.")

    # Always close the connection when finished
    db.close()

if __name__ == "__main__":
    main()
