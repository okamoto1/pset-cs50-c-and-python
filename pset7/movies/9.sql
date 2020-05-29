SELECT name
FROM people WHERE id IN (SELECT DISTINCT (people.id) FROM people
JOIN stars, movies
ON stars.movie_id = movies.id AND people.id = stars.person_id
WHERE year = 2004)
ORDER BY birth ASC;