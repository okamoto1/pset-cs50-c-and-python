SELECT title 
FROM movies 
JOIN people, stars
ON stars.movie_id = movies.id AND stars.person_id = people.id
WHERE people.id IN (SELECT people.id FROM people WHERE name IN ('Johnny Depp', 'Helena Bonham Carter'))
GROUP BY movies.id
HAVING count(title) > 1;