import os
import subprocess
from concurrent.futures import ProcessPoolExecutor
import multiprocessing

# Get the number of CPU cores
cpu_count = multiprocessing.cpu_count()

def convert_pdf(file):
    # Output file name
    output_file = 'compressed-' + file
    # Imagemagick conversion command
    command = [
        'convert', '-density', '150x150', '-quality', '60',
        '-compress', 'jpeg', file, output_file
    ]
    # Execute command
    subprocess.run(command, check=True)
    
    # Check file size, report if more than 100 MiB
    file_size = os.path.getsize(output_file)
    if file_size > 100 * 1024 * 1024:  # 100 MiB in bytes
        print(f"The file {output_file} is larger than 100 MiB.")

    return f"Converted {file} to {output_file}."

def should_process(file):
    # Check if file is a PDF and does not start with "compressed-"
    return file.lower().endswith('.pdf') and not file.startswith('compressed-')

# List PDF files that should be processed
pdf_files = [f for f in os.listdir('.') if should_process(f)]

# Process files in parallel using the number of available CPU cores
with ProcessPoolExecutor(max_workers=cpu_count) as executor:
    results = list(executor.map(convert_pdf, pdf_files))

for result in results:
    print(result)


