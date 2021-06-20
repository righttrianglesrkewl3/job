def tournamentWinner(competitions, results):
  # Write your code here.
	scores = {}
	rows = zip(competitions, results)
	for row in rows:
		print(row[0], row[1])
		if row[1]== 0:
			print(row[0][1])
			scores[row[0][1]] = scores.get(row[0][1], 0) + 3

		elif row[1] == 1:
			print(row[0][0])
			scores[row[0][0]] = scores.get(row[0][0], 0) + 3
    return str(max(scores, key=scores.get))
