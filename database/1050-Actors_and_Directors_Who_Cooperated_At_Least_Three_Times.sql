Select actor_id, director_id
From ActorDirector
Group by actor_id, director_id
Having count(timestamp) >= 3;