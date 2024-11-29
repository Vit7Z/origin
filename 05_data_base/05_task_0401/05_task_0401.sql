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
VALUES (100, 101),
       (100, 102),
       (120, 123),
       (120, 124),
       (140, 145),
       (140, 146);