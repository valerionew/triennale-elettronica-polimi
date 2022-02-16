for f in ./*.pdf; do
    convert -density 300 -compress zip "${f%.*}".pdf "${f%.*}"-300-raster.pdf
    convert -density 150 -compress zip "${f%.*}".pdf "${f%.*}"-150-raster.pdf
done
