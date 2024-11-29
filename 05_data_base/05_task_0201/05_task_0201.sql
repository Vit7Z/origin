CREATE TABLE if not exists Genre
(
    id SERIAL NOT NULL PRIMARY KEY,
    genre_name CHARACTER VARYING(32) NOT NULL
);

CREATE TABLE if not exists Artist
(
    id SERIAL NOT NULL PRIMARY KEY,
    artist_name CHARACTER VARYING(64) NOT NULL,
    genre_name CHARACTER VARYING(32) NOT NULL
);

/* connection_1 */
CREATE TABLE if not exists GenreArtist
(
    genre_id INTEGER NOT NULL REFERENCES Genre (id),
    artist_id INTEGER NOT NULL REFERENCES Artist (id),
    PRIMARY KEY (genre_id, artist_id)
);

CREATE TABLE if not exists Album
(
    id SERIAL NOT NULL PRIMARY KEY,
    album_title CHARACTER VARYING(64) NOT NULL,
    album_year INTEGER NOT NULL,
    artist_name CHARACTER VARYING(64) NOT NULL
);

/* album_track CHARACTER VARYING(64) NOT NULL */

/* connection_2 */
CREATE TABLE if not exists ArtistAlbum
(
    artist_id SERIAL NOT NULL REFERENCES Artist (id),
    album_id SERIAL NOT NULL REFERENCES Album (id),
    PRIMARY KEY (artist_id, album_id)
);

CREATE TABLE if not exists Track
(
    id SERIAL NOT NULL PRIMARY KEY,
    track_title CHARACTER VARYING(128) NOT NULL,
    track_duration TIME NOT NULL,
    album_id INTEGER NOT NULL REFERENCES Album (id)
);

CREATE TABLE if not exists Collection
(
    id SERIAL NOT NULL PRIMARY KEY,
    collection_title CHARACTER VARYING(64) NOT NULL,
    collection_year INTEGER NOT NULL
);

/* connection_3 */
CREATE TABLE if not exists TrackCollection
(
    track_id SERIAL NOT NULL REFERENCES Track (id),
    collection_id SERIAL NOT NULL REFERENCES Collection (id),
    PRIMARY KEY (track_id, collection_id)
);