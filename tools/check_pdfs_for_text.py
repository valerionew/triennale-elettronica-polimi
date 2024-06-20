import os
import fitz  # PyMuPDF

def is_textless_pdf(file_path):
    try:
        document = fitz.open(file_path)
        for page in document:
            if page.get_text().strip():  # Check if there is any text
                return False  # There is text, so it's not a textless PDF
        return True  # No text found in any page
    except Exception as e:
        print(f"Failed to process {file_path}: {e}")
        return False  # Assume it is not textless if there is an error opening the file

def find_textless_pdfs(root_directory):
    textless_pdfs = []
    for root, dirs, files in os.walk(root_directory):
        for file in files:
            if file.lower().endswith('.pdf'):
                full_path = os.path.join(root, file)
                if is_textless_pdf(full_path):
                    size_in_mb = os.path.getsize(full_path) / 1024 / 1024  # Convert size from bytes to MB
                    textless_pdfs.append((full_path, size_in_mb))
    return textless_pdfs

# Specify the root directory of your PDF files
root_dir = 'static/'
textless_pdfs = find_textless_pdfs(root_dir)

total_size = 0
# Print the list of PDFs without text, along with their size in MB
for pdf, size in textless_pdfs:
    print(f"{pdf}: {size:.2f} MB")
    total_size += size

print(f'Total size: {total_size:.2f} MB')

