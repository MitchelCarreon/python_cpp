def writeAndCreate(imageDimensions):
    red = 0
    green = 255
    blue = 0

    maxColorVal = 255
    binaryFormat = 'P3'

    size = imageDimensions[0] * imageDimensions[1]
    print('Choose # from the list of built-in patterns\nStripes\nWaves')
    choice = input('Input: ')
    with open('Sample.ppm', 'w') as file:
        file.write(f'{binaryFormat}\n'
                   f'{imageDimensions[0]} {imageDimensions[1]}\n'
                   f'{maxColorVal}\n')

        if choice == '0':
            print("Creating Stripes...\n")
            line_pixels = size / 10
            rgb = [0, 0, 0]

            i = 0
            while i < size:
                if i < line_pixels:
                    file.write(f'{rgb[0]} {rgb[1]} {rgb[2]}\n')
                    i += 1
                else:
                    line_pixels += size / 10
                    rgb[1] = 255 if rgb[1] == 0 else 0
                    rgb[2] = rgb[0]
        elif choice == '1':
            print("Creating Waves...\n")
            file.write(f'P3\n'
                       f' {size}\n'
                       f'{maxColorVal}\n')
            for i in range(0, size):
                if red > 255:
                    red = 50
                else:
                    red += 1

                if green <= 0:
                    green = 25
                else:
                    green -= 1

                if blue > 255:
                    blue = 100
                else:
                    blue += 1

                file.write(f'{red} {green} {blue}\n')

        print("PPM Created...\n")

def read(file_name):
    with open(file_name, 'r') as file:
        for line in file:
            print(line)


if __name__ == '__main__':
    writeAndCreate([300, 200])
    # read('Sample.ppm')

    pass
