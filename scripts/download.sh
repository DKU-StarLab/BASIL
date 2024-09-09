#! /usr/bin/env bash

# Download dataset from SOSD 
# https://github.com/learnedsystems/SOSD/blob/master/scripts/download.sh

# Calculate md5 checksum of FILE and stores it in MD5_RESULT
function get_checksum() {
   FILE=$1

   if [ -x "$(command -v md5sum)" ]; then
      # Linux
      MD5_RESULT=`md5sum ${FILE} | awk '{ print $1 }'`
   else
      # OS X
      MD5_RESULT=`md5 -q ${FILE}`
   fi
}

function download_file_zst() {
   FILE=$1;
   CHECKSUM=$2;
   URL=$3;

   # Check if file already exists
   if [ -f ${FILE} ]; then
      # Exists -> check the checksum
      get_checksum ${FILE}
      if [ "${MD5_RESULT}" != "${CHECKSUM}" ]; then
         wget -O - ${URL} | zstd -d > ${FILE}
      fi
   else
      # Does not exists -> download
      wget -O - ${URL} | zstd -d > ${FILE}
   fi

   # Validate (at this point the file should really exist)
   get_checksum ${FILE}
   if [ "${MD5_RESULT}" != "${CHECKSUM}" ]; then
      echo "error checksum does not match: run download again"
      exit -1
   else
      echo ${FILE} "checksum ok"
   fi
}

# Main script code
function large() {
   cd data

   download_file_zst books_800M_uint64 8708eb3e1757640ba18dcd3a0dbb53bc https://www.dropbox.com/s/y2u3nbanbnbmg7n/books_800M_uint64.zst?dl=1
   download_file_zst osm_800M_uint64 70670bf41196b9591e07d0128a281b9a https://www.dropbox.com/s/j1d4ufn4fyb4po2/osm_cellids_800M_uint64.zst?dl=1
   
   cd ..
   echo "done"
}

echo "Downloading data ..."
mkdir -p data

# Download dataset from GRE
# https://github.com/gre4index/GRE/blob/master/datasets/download.sh

for d in history stack covid books genome osm fb libio planet wise wiki
do
wget --no-check-certificate -nc -O data/${d}_200M_uint64 https://www.cse.cuhk.edu.hk/mlsys/gre/$d
done

large