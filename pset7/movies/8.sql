SELECT name
FROM people
JOIN stars, movies
ON stars.movie_id = movies.id AND people.id = stars.person_id
WHERE title = 'Toy Story';