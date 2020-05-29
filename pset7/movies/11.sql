SELECT title
FROM movies
JOIN people, stars, ratings
ON people.id = stars.person_id AND movies.id = stars.movie_id AND movies.id = ratings.movie_id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;