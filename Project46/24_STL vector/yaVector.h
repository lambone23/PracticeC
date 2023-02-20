#pragma once

namespace ya
{
	template <typename T>
	class vector
	{
	public:
		vector(size_t cap = DEFAULT_CAP)
			: mArr(new T(cap + 1))
			, mSize(0)
			, mCapacity(cap)
		{

		}
		~vector()
		{
			delete[] mArr;
		}

		void resize(size_t size, int value = 0)
		{
			T* newArr = new T[size + 1];
			mSize = (mSize < size ? mSize : size);
			//if (mSize < size)
			//{
			//	mSize = mSize;
			//}
			//else /*if (mSize >= size)*/
			//{
			//	mSize = size;
			//}

			mCapacity = size;

			for (size_t i = 0; i < mSize; i++)
				newArr[i] = mArr[i];
			for (size_t i = mSize; i < mCapacity; i++)
				newArr[i] = value;

			delete[] mArr;
			mArr = newArr;
			mSize = size;
		}

		void push_bakc(const T& value)
		{
			if (mSize >= mCapacity)
			{
				if (mCapacity < DEFAULT_CAP)
					mCapacity = DEFAULT_CAP;
				else
					mCapacity = 2 * mCapacity - (mCapacity / 2);

				T* newArr = new T[mCapacity + 1];
				for (size_t i = 0; i < mSize; i++)
				{
					newArr[i] = mArr[i];
				}
				delete[] mArr;
				mArr = newArr;
			}

			mArr[mSize++] = value;
		}

		void pop_back()
		{
			mSize = mSize > 0 ? mSize - 1 : 0;
		}

		T* begin() const { return mArr; /* &mArr[0];*/ }
		T* end() const { return &mArr[mSize]; }

		size_t size() { return mSize; }
		size_t capacity() { return mCapacity; }

		T& operator[](size_t idx) { return mArr[idx]; }
		vector& operator=(const vector& other)
		{
			if (this != nullptr)
			{
				if (mCapacity < other.mCapacity)
				{
					delete[] mArr;
					mCapacity = other.mCapacity;
					mArr = new T[mCapacity];
				}

				mSize = other.mSize;
				for (size_t i = 0; i < mSize; i++)
					mArr[i] = other.mArr[i];
			}

			return *this;
		}

		void clear() { mSize = 0; }

	private:
		static constexpr size_t DEFAULT_CAP = 5;

		T* mArr;
		size_t mSize;
		size_t mCapacity;
	};


}