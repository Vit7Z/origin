#1. �������� � ����������������� ������ ����������� �����.
SELECT track_title, track_duration 
 FROM track 
 WHERE track_duration = (SELECT MAX(track_duration) FROM track);
 
#2. �������� ������, ����������������� ������� �� ����� 3,5 �����.
SELECT track_title, track_duration 
 FROM track 
 WHERE track_duration > '00:03:29'
 ORDER BY track_duration ASC;
 
#3. �������� ���������, �������� � ������ � 2018 �� 2020 ���� ������������.
SELECT collection_title, collection_year
  FROM collection 
  WHERE collection_year BETWEEN 2018 AND 2020;
  
#4. �����������, ��� ��� ������� �� ������ �����.
SELECT artist_name 
 FROM artist 
 WHERE artist_name NOT LIKE '%% %%';
 
#5. �������� ������, ������� �������� ����� ���� ��� �my�.
SELECT track_title 
 FROM track 
 WHERE track_title LIKE '%%my%%' OR track_title LIKE '%%My%%';