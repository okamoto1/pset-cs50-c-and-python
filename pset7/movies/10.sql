SELECT name
FROM people
WHERE id IN (SELECT DISTINCT (people.id) FROM people
JOIN ratings ON ratings.movie_id = directors.movie_id
JOIN directors ON directors.person_id = people.id
WHERE rating >= 9.0);