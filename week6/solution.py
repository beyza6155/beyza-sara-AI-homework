# Project 1 — Temperature Converter
# Author: Gemini
# Date: May 8, 2026

# ── Your solution goes here ───────────────────────────────────────────────────

celsius = float(input("Enter temperature in Celsius: "))

# Calculate fahrenheit using the formula F = (C × 9/5) + 32
fahrenheit = (celsius * 9/5) + 32

# Print the result using an f-string
# Use :.1f if you want to round to one decimal place
print(f"{celsius}°C is equal to {fahrenheit}°F")

# ── Bonus (optional) ─────────────────────────────────────────────────────────
# Add a direction menu (C→F or F→C)

print("\n--- Advanced Converter ---")
choice = input("Convert from (C)elsius or (F)ahrenheit? ").upper()

if choice == "C":
    c = float(input("Celsius: "))
    f = (c * 9/5) + 32
    print(f"Result: {f:.2f}°F")
elif choice == "F":
    f = float(input("Fahrenheit: "))
    c = (f - 32) * 5/9
    print(f"Result: {c:.2f}°C")
else:
    print("Invalid choice.")
