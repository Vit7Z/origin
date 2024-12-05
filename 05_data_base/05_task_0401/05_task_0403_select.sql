# 1. Количество исполнителей в каждом жанре.
SELECT genre_name, COUNT (artist_name) FROM artist
   JOIN genreartist ON artist.id = genreartist.artist_id
   GROUP BY genre_name ORDER BY genre_name ASC;


#2. Количество треков, вошедших в альбомы 2019–2020 годов.
SELECT album_year, COUNT (track_title) FROM album a
    JOIN track t ON a.id = t.album_id
    WHERE a.album_year >= 2019 AND a.album_year <= 2020
    GROUP BY album_year;


#3. Средняя продолжительность треков по каждому альбому.
SELECT album_title, AVG (track_duration) FROM album a
    JOIN track t ON a.id = t.album_id
    GROUP BY album_title ORDER BY AVG (track_duration) ASC;


#4. Все исполнители, которые не выпустили альбомы в 2020 году.
SELECT artist_name, album_year FROM album 
    WHERE album_year != 2020
    ORDER BY artist_name ASC, album_year;


#5. Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами)
SELECT collection_title FROM collection d
  JOIN trackcollection cd  ON d.id = cd.collection_id
  JOIN track t  ON cd.track_id = t.id
  JOIN album a  ON t.album_id = a.id
  JOIN artistalbum ma  ON a.id = ma.album_id
  JOIN artist m ON ma.artist_id = m.id
  WHERE m.artist_name LIKE 'Eminem'
  GROUP BY collection_title;