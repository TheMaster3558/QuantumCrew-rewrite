$errorActionPreference='Stop'; .\astyle --style=java --style=attach -A2 --recursive *.cpp,*.h; Remove-Item * -Recurse -Include *.orig
