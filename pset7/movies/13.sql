SELECT DISTINCT(name)
FROM people
JOIN movies, stars
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE NOT name = 'Kevin Bacon' AND movies.id IN (SELECT movies.id FROM movies
JOIN people, stars
ON movies.id = stars.movie_id AND stars.person_id = people.id
WHERE name = 'Kevin Bacon' AND birth = 1958);



