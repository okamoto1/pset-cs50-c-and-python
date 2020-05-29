SELECT title AS titu, rating AS n
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE year = 2010 AND rating IS NOT NULL
ORDER BY n DESC,
titu ASC;
