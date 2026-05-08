import csv

def clean_data():
    input_file = 'messy_data.csv'
    output_file = 'cleaned_data.csv'
    
    report = {
        "total_rows": 0,
        "cleaned_names": 0,
        "fixed_ages": 0,
        "missing_values": 0
    }

    with open(input_file, 'r') as infile, open(output_file, 'w', newline='') as outfile:
        reader = csv.DictReader(infile)
        writer = csv.DictWriter(outfile, fieldnames=reader.fieldnames)
        writer.writeheader()

        for row in reader:
            report["total_rows"] += 1
            is_dirty = False

            # 1. Clean Names: Strip whitespace and Title Case
            original_name = row['name']
            row['name'] = original_name.strip().title()
            if row['name'] != original_name:
                report["cleaned_names"] += 1

            # 2. Clean Email: Lowercase and strip
            row['email'] = row['email'].strip().lower()

            # 3. Handle Ages: Validate if it's a number
            age_str = row['age'].strip()
            if not age_str:
                report["missing_values"] += 1
                row['age'] = "0"  # Default value
            elif not age_str.isdigit():
                report["fixed_ages"] += 1
                row['age'] = "0"  # Reset invalid data
            else:
                row['age'] = age_str

            writer.writerow(row)

    # Print Summary Report
    print("--- Data Cleaning Report ---")
    print(f"Rows Processed:   {report['total_rows']}")
    print(f"Names Reformatted: {report['cleaned_names']}")
    print(f"Invalid Ages:     {report['fixed_ages']}")
    print(f"Empty Values:     {report['missing_values']}")
    print(f"\nCleaned data saved to: {output_file}")

if __name__ == "__main__":
    clean_data()
