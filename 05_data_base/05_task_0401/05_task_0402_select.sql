#1. Название и продолжительность самого длительного трека.
SELECT track_title, track_duration 
 FROM track 
 WHERE track_duration = (SELECT MAX(track_duration) FROM track);
 
#2. Название треков, продолжительность которых не менее 3,5 минут.
SELECT track_title, track_duration 
 FROM track 
 WHERE track_duration > '00:03:29'
 ORDER BY track_duration ASC;
 
#3. Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT collection_title, collection_year
  FROM collection 
  WHERE collection_year BETWEEN 2018 AND 2020;
  
#4. Исполнители, чьё имя состоит из одного слова.
SELECT artist_name 
 FROM artist 
 WHERE artist_name NOT LIKE '%% %%';
 
#5. Название треков, которые содержат слова «мой» или «my».
SELECT track_title 
 FROM track 
 WHERE track_title LIKE '%%my%%' OR track_title LIKE '%%My%%';