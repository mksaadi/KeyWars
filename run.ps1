g++ src/*.cpp -o game.exe -O1 -Wall -Wno-missing-braces -std=c++17 -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

# Check if the build was successful
if ($LASTEXITCODE -eq 0) {
    # Run the compiled executable
    ./game.exe
} else {
    Write-Host "Build failed. Please check the errors." -ForegroundColor Red
}