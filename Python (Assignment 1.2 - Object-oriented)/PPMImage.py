from BaseImage import BaseImage


class PPMImage(BaseImage):
    def __init__(self, dimensions, themes, binary_format='P3', max_color_val=255):
        super().__init__(dimensions, themes, binary_format)
        self._maxColorVal = max_color_val

    def read(self, file_name):
        with open(file_name, 'r') as file:
            for line in file:
                print(line)

    def draw(self, file_name):
        self._themes.init(self, self._patterns)
        self._choose_pattern().create()
        self._write_to(file_name)

    def _choose_pattern(self):
        print('Choose # from the list of built-in patterns')
        for pattern in self._patterns:
            print(pattern)
        choice = int(input('Input: '))
        if choice <= -1:
            print('CHOICES START AT 0. By default, pattern 0 is chosen for you.')
            return self._patterns[0]

        return self._patterns[choice]

    def _write_to(self, file_name):
        print('Writing to file...')

        with open(file_name, 'w') as file:
            file.write(f'{self._binaryFormat}\n'
                       f'{self._Dimensions.width} {self._Dimensions.height}\n'
                       f'{self._maxColorVal}\n')

            for pixel in self._pixels:
                file.write(str(pixel))

        print("PPM Created")
