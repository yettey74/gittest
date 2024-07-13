# Define repository paths
$repo1 = "c:\project\cpp\gittest"
$repo2 = "c:\project\cpp\gameServer"

# Generate custom log files
gource --output-custom-log log1.txt $repo1
gource --output-custom-log log2.txt $repo2

# Add repository names to paths (optional)
<# 
Get-Content log1.txt | ForEach-Object { $_ -replace '^(.+)\|', '$1|/gittest|' } | Set-Content log1_modified.txt
Get-Content log2.txt | ForEach-Object { $_ -replace '^(.+)\|', '$1|/gameServer|' } | Set-Content log2_modified.txt 
#>

# Combine the logs
# $log1 = Get-Content log1_modified.txt
# $log2 = Get-Content log2_modified.txt
# $combined = $log1 + $log2

$log1 = Get-Content log1.txt
$log2 = Get-Content log2.txt
$combined = $log1 + $log2

# Sort the combined logs by the timestamp
$sortedCombined = $combined | Sort-Object {
    [datetime]::FromFileTimeUtc((($_.Split('|')[0]) -as [double]) * [timespan]::TicksPerSecond)
}

# Save the sorted logs
$sortedCombined | Set-Content combined.txt

git log --pretty="%at|%as %s" > captions.txt

# Visualize with Gource, adjusting settings for complete tree display
gource combined.txt --auto-skip-seconds 1 --max-files 10000

gource combined.txt --auto-skip-seconds 1 --max-files 10000 --output-ppm-stream - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i pipe: -vcodec libx264 -preset ultrafast -pix_fmt yuv420p -crf 1 -threads 0 output.mp4

gource --load-config gource.config --output-ppm-stream - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i pipe: -vcodec libx264 -preset medium -pix_fmt yuv420p -crf 1 -threads 0 -bf 0 output/gource_intermediary.mp4

# Merge of both methods
gource --load-config gource.config combined.txt --output-ppm-stream - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i pipe: -vcodec libx264 -preset medium -pix_fmt yuv420p -crf 1 -threads 0 output.mp4


gource --load-config gource.config --output-ppm-stream - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i pipe: -vcodec libx264 -preset medium -pix_fmt yuv420p -crf 1 -threads 0 -bf 0 output/gource_intermediary.mp4
