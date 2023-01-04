import csv
import sys


def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py databases/FILENAME.csv sequences/FILENAME.txt")

    database = []
    with open(sys.argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile)
        subsequences = reader.fieldnames[1:]
        for row in reader:
            database.append(row)

    txtfile = open(sys.argv[2], "r")
    dna = txtfile.read()

    strs_dna = {}
    for subsequence in subsequences:
        longest_run = longest_match(dna, subsequence)
        strs_dna[subsequence] = longest_run

    for person in database:
        if match(subsequences, strs_dna, person):
            print(person['name'])
            return
    print("No match")
    return

def match(subsequences, strs_dna, person):
    for subsequence in subsequences:
        if strs_dna[subsequence] != int(person[subsequence]):
            return False
    return True

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)
    return longest_run


main()
