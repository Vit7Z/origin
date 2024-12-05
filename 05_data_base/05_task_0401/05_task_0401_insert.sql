INSERT INTO Genre  (genre_name)
VALUES ('Rock'), ('Rap'), ('Pop');

INSERT INTO Artist (artist_name, genre_name)
VALUES ('Bon Jovi', 'Rock'), 
       ('Offspring', 'Rock'),
       ('50 Cent', 'Rap'),
       ('Eminem', 'Rap'),
       ('The Black Eyed Peas', 'Pop'),
       ('Lady Gaga', 'Pop');
              
INSERT INTO Album (album_title, album_year, artist_name)    
VALUES ('Slippery When Wet', 1986, 'Bon Jovi'), 
       ('Crush', 2000, 'Bon Jovi'),    
       ('New Jersey', 1988, 'Bon Jovi'),
       ('2020', 2020, 'Bon Jovi'),
       ('Americana', 1998, 'Offspring'),
       ('Let the Bad Times Roll', 2021, 'Offspring'),
       ('The Massacre', 2005, '50 Cent'),
       ('Get Rich or Die Tryin', 2003, '50 Cent'),
       ('8 mile', 2002, 'Eminem'),
       ('Encore', 2004, 'Eminem'),
       ('The Eminem Show', 2002, 'Eminem'),
       ('Music to Be Murdered By', 2020, 'Eminem'),
       ('Elephunk', 2004, 'The Black Eyed Peas'),
       ('Monkey Business', 2006, 'The Black Eyed Peas'),
       ('Masters of the Sun Vol. 1', 2018, 'The Black Eyed Peas'),
       ('Chromatica', 2020, 'Lady Gaga');
       
INSERT INTO Track (track_title, track_duration, album_id)
VALUES ('You Give Love a Bad Name', '0:03:42', 1),
       ('It’s My Life', '0:03:45', 2),
       ('Bad Medicine', '0:05:19', 3),
       ('Do What You Can', '0:04:17', 4);

INSERT INTO Track (track_title, track_duration, album_id)
VALUES ('The Kids Aren’t Alright', '0:03:00', 5),
       ('Pretty Fly (For A White Guy)', '0:03:08', 5),
       ('Behind Your Walls', '0:03:21', 6);

INSERT INTO Track (track_title, track_duration, album_id)	
VALUES ('Candy Shop', '0:03:29', 7),
       ('In Da Club', '0:03:13', 8);
              
INSERT INTO Track (track_title, track_duration, album_id)
VALUES ('Lose Yourself', '0:05:26', 9),
       ('Mockingbird', '0:04:11', 10),
       ('Sing for the Moment', '0:05:40', 11),
       ('Without Me', '0:04:51', 11),
       ('Darkness', '0:05:37', 12);
       
INSERT INTO Track (track_title, track_duration, album_id)
VALUES ('Let''s Get It Started', '0:03:37', 13),
       ('Pump It', '0:03:33', 14),
       ('Get Ready', '0:04:10', 15);
              
INSERT INTO Track (track_title, track_duration, album_id)
VALUES ('Stupid Love', '0:03:13', 16),
       ('Free Woman', '0:03:11', 16);     
       
INSERT INTO Collection (collection_title, collection_year)
VALUES ('This Left Feels Right', 2000),
       ('Rock Now', 2014),
       ('Greatest Hits', 2021),
       ('Golden Hits', 2018),
       ('Rock Now', 2014),
       ('Before I Self Destruct: The Selects', 2005),
       ('Shady XV', 2002),
       ('Eminem Presents: The Re-Up', 2004),
       ('The E.N.D. Summer', 2023);
        
INSERT INTO GenreArtist (genre_id, artist_id)
VALUES (1, 1),
       (1, 2),
       (2, 3),
       (2, 4),
       (3, 5),
       (3, 6);

INSERT INTO Artist (artist_name, genre_name)
VALUES ('Alice Cooper', 'Rock'),
       ('Miley Ray Cyrus', 'Pop'),
       ('Morgan Wallen', 'Pop');
       
INSERT INTO GenreArtist (genre_id, artist_id)
VALUES (1, 7),
       (3, 8),
       (3, 9);
       
INSERT INTO Album (album_title, album_year, artist_name)    
VALUES ('Detroit Stories', 2021, 'Alice Cooper'), 
       ('Plastic Hearts', 2020, 'Miley Ray Cyrus'),    
       ('If I Know Me', 2018, 'Morgan Wallen');
       
INSERT INTO Track (track_title, track_duration, album_id)
VALUES ('Our Love Will Change the World', '0:03:39', 17),
       ('Angels like You', '0:03:16', 18),
       ('If I Know Me', '0:03:28', 19);

INSERT INTO ArtistAlbum (artist_id, album_id)
VALUES (1, 1),
       (1, 2),
       (1, 3),
       (1, 4),
       (2, 5),
       (2, 6),
       (3, 7),
       (3, 8), 
       (4, 9),
       (4, 10),
       (4, 11),
       (4, 12),
       (5, 13),
       (5, 14),
       (5, 15),
       (6, 16),
       (7, 17),
       (8, 18),
       (9, 19);       
              
INSERT INTO TrackCollection (track_id, collection_id)
VALUES (1, 1),
       (2, 2),
       (3, 1),
       (4, 3),
       (5, 4),
       (6, 5),
       (7, 3),
       (8, 6), 
       (9, 4),
       (10, 7),
       (11, 8),
       (12, 9),
       (13, 3),
       (14, 3),
       (15, 9),
       (16, 4),
       (17, 3),
       (18, 9),
       (19, 9),
			 (20, 5),
       (21, 9),
       (22, 9);