@echo off
echo Activating virtual environment...
.\venv\Scripts\activate.bat
echo Virtual environment activated.
echo Running Python Django script...
python manage.py runserver 0.0.0.0:8000
echo "bye bye from Mr.neg"